
#include "AdlDeviceFactorySingleton.h"
#include "AdlinkCommon.h"
#include "AdlHelp.h"
#include <iostream>
#include <omnithread.h>
#include <cassert>
#include <dask.h>

namespace {

using namespace AdlDeviceFactorySingleton_;

static const AdlBoardParams __DAQ_2205 = {
	"DAQ_2205",
	DAQ_2205,
	true,
	{1, 1, 1, 2},
	64, //64/32 AI; 2 AO
	// 64 single-ended or 32 differential-input
	2,
	40000000,
	80,
	16777215,
	1024,
	16,
	12,
};

static const AdlBoardParams __DAQ_2213 = {
	"DAQ_2213",
	DAQ_2213,
	true,
	{1, 0, 1, 2},
	16, //16/8 AI; 0 AO
	16, // 16 single-ended or 8 diferential-input
	0,
	40000000,
	160,
	16777215,
	1024,
	16,
	0,
};

static const AdlBoardParams __DAQ_2502 = {
	"DAQ_2502",
	DAQ_2502,
	true,
	{1, 1, 1, 2},
	8, // 4 ai, 8 ao
	4,
	8,
	40000000,
	100,
	16777215,
	/// @todo VERY IMPORTANT re-design need, as this board has two independent buffers for analog input and analog output!!!!
 	//onBoardBufferSz : 2048, // Analog input
	16384, // Analog output
	14,
	12,
};

static const AdlBoardParams __DAQ_2005 = {
	"DAQ_2005",
	DAQ_2005,
	true,
	{1, 1, 1, 2},
	4, // 4 ai / 2 ao
	4,
	2,
	40000000,
	80,
	16777215,
 	512,
	16,
	12,
};

static const AdlBoardParams __DAQ_2010 = {
	"DAQ_2010",
	DAQ_2010,
	true,
	{1, 1, 1, 2},
	4, // 4 ai / 2 ao
	4,
	2,
	40000000,
	20,
	16777215,
	8192,
	14,
	12,
};

static const AdlBoardParams __PCI_6202 = {
	///@todo find out and define here the correct parameters
	"PCI_6202",
	PCI_6202,
	false,
	{0, 1, 0, 0},
	4,
	0,
	4,
	80000000,
	20, //todo
	16777215, //todo
	512,
	0,
	16,
};

static const AdlBoardParams __PCI_6208V = {
	///@todo find out and define here the correct parameters
	"PCI_6208V",
	PCI_6208V,
	false,
	{0, 1, 0, 0},
	8,
	0,
	8,
	40000000, //todo
	20, //todo
	16777215, //todo
	16, //todo
	0,
	16,
};

static const AdlBoardParams __PCI_6208A = {
	///@todo find out and define here the correct parameters
	"PCI_6208A",
	PCI_6208A,
	false,
	{0, 1, 0, 0},
	8,
	0,
	8,
// todo BEGIN ------------------------
	24000000,
	96,
	16777215,
	1024,
// todo END --------------------------
	0,
	16,
};

static const AdlBoardParams __PCI_9116 = {
	"PCI_9116",
	PCI_9116,
	false,
	{1, 0, 1, 0},
	64,
	64,
	0,
	24000000,
	96,
	16777215,
	1024,
	16,
	0,
};

};


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/*static*/ AdlDeviceFactorySingleton::CardMap AdlDeviceFactorySingleton::s_cardMap;
/*static*/ AdlDeviceFactorySingleton::CommonMap AdlDeviceFactorySingleton::s_commonMap;
/*static*/ omni_mutex AdlDeviceFactorySingleton::s_mutex;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

AdlDeviceFactorySingleton::AdlDeviceFactorySingleton()
{
	// This constructor is defined private just to avoid ANY object of this
	// class to be created
	assert(false);
}

const AdlDeviceFactorySingleton::AdlBoardParams* AdlDeviceFactorySingleton::get_board_params(const std::string & boardType)
{
	if      (boardType == "DAQ_2205")	{ return &__DAQ_2205; }
	else if (boardType == "DAQ_2213")	{ return &__DAQ_2213; }
	else if (boardType == "DAQ_2502")	{ return &__DAQ_2502; }
	else if (boardType == "DAQ_2005")	{ return &__DAQ_2005; }
	else if (boardType == "DAQ_2010")	{ return &__DAQ_2010; }
	else if (boardType == "PCI_6202")	{ return &__PCI_6202; }
	else if (boardType == "PCI_6208V")	{ return &__PCI_6208V; }
	else if (boardType == "PCI_6208A")	{ return &__PCI_6208A; }
	else if (boardType == "PCI_9116")	{ return &__PCI_9116; }
	
	return 0;
}

/*static*/ void AdlDeviceFactorySingleton::get_supported_boards(std::vector<std::string> &boards)
{
	boards.push_back("DAQ_2205");
	boards.push_back("DAQ_2213");
	boards.push_back("DAQ_2502");
	boards.push_back("DAQ_2005");
	boards.push_back("DAQ_2010");
	boards.push_back("PCI_6202");
	boards.push_back("PCI_6208V");
	boards.push_back("PCI_6208A");
	boards.push_back("PCI_9116");
}

// It is tempting to define:
// - const AdlDeviceFactorySingleton::AdlBoardParams* AdlDeviceFactorySingleton::get_board_params(I16 boardType)
// But it's not feasible because PCI and DAQ macros can be repeated (ex DAQ_2010 = PCI6208V) so
// we cannot take them as universal board type identifyier, we need the string!!

/**
 * @brief Helper to ensure that only one pyiscal card is registered per process.
 *
 * Originally this file allowed to register any number of pysical devices
 * per process. But this approach is not compatible with signal callback
 * mechanisms of the Adlink API (See NOTES_ON_SIGNALS.TXT). So, now we
 * must ensure that only one physical device can be registered at a given
 * time of the process. Instead of rewriting a simplifyed version of
 * this, I have added this function that just checks if the physical board
 * requested to register as virtual is alone.
 * 
 * If someday problems with signals become somehow solved, just make sure
 * this method returns always 'true' to go back to the old behavior.
 * 
*/
bool AdlDeviceFactorySingleton::_check_single(const AdlBoardParams* params, U16 cardNum)
{
	AdlDeviceFactorySingleton::CardMap & m = AdlDeviceFactorySingleton::s_cardMap;
	AdlDeviceFactorySingleton::CardTypeNumPair tn(params, cardNum);

	// Check if there's any board registered
	if (!m.size())
		return true;

	// That's what this method helps to ensure!
	assert(m.size() == 1);

	// There's a card registered, check if it is this one
	AdlDeviceFactorySingleton::CardMap::iterator i, e = m.end();
	i = m.find(tn);
	if ( i == e )
		return false;

	// There's card registered, this one
	return true;
}


I16 AdlDeviceFactorySingleton::get(DevicePartInterface** dev, const std::string & boardType, U16 cardNum, ADFMode mode)
{
	CommonDeviceInterface* commonDev = 0;
	std::string mis = "AdlDeviceFactorySingleton: ";

	const AdlBoardParams* params = get_board_params(boardType);

	if (!params) {
		std::cerr << mis << " Unknown board type" << std::endl;
		return -1;
	}

	I16 err = __get_common(&commonDev, params, cardNum, mode);
	if (err != NoError)
		return err;

	try {
		switch (mode) {
			case ModeAnalogInput:
				if (params->isD2K)
					*dev = create_input_device_d2k(commonDev);
				else
					*dev = create_input_device_psdask(commonDev);
				break;
			case ModeAnalogOutput:
				if (params->isD2K)
					*dev = create_output_device_d2k(commonDev);
				else
					*dev = create_output_device_psdask(commonDev);
				break;
			case ModeDigital:
				*dev = create_digital_device(commonDev);
				break;
			case ModeCounter:
				*dev = create_counter_device(commonDev);
				break;
			default:
				*dev = 0;
				return -1;
		}
	} catch (AdlExcept &e) {
		__release_common(&commonDev, mode);
		std::cerr	<< mis << " unable to complete operation! " 
					<< mode << e.what() << std::endl;
		throw;
	} catch (...) {
		__release_common(&commonDev, mode);
		std::cerr << mis << " unable to complete operation! " << mode << std::endl;
		//throw;
		return -1;
	}
	std::cout << mis << " card successfully registered for mode " << mode << std::endl;
	return NoError;
}

I16 AdlDeviceFactorySingleton::__get_common(CommonDeviceInterface** dev, const AdlBoardParams* params, U16 cardNum, ADFMode mode)
{
	CommonDeviceInterface* commonDev = 0;

	omni_mutex_lock lock(s_mutex);
	std::string mis = "AdlDeviceFactorySingleton: ";

	assert(*dev == 0);

	if (! _check_single(params, cardNum) ) {
		std::cout	<< mis << "Only one physical board can be registered"
					<< " in the same process." << std::endl;
		return -1;
	}

	AdlDeviceFactorySingleton::CardMap & m = AdlDeviceFactorySingleton::s_cardMap;
	AdlDeviceFactorySingleton::CardTypeNumPair tn(params, cardNum);
	AdlDeviceFactorySingleton::CardMap::iterator i, e = m.end();
	i = m.find(tn);

	if (i == e) {
		std::cout << mis << "Registering device " << cardNum << std::endl;
		
		I16 cid;
		if(params->isD2K) {
			mis += "D2K";
			cid = D2K_Register_Card(params->type, cardNum);
		} else {
			mis += "PCI";
			cid = Register_Card(params->type, cardNum);
		}
		if (cid < 0)
			return cid;
		m[tn] = OpenCardMode();
		m[tn].first = cid;
		i = m.find(tn);
		if (params->isD2K)
			s_commonMap[tn] = new CommonDeviceD2K(params, cardNum, cid);
		else
			s_commonMap[tn] = new CommonDevicePSDASK(params, cardNum, cid);
		std::cout << mis << " card registered" << std::endl;
	} else
		std::cout << mis << "Card already registered, trying to reuse" << std::endl;
	

	OpenCardMode & cardEtMode = i->second;
	OpenCardModesSet & modeSet = cardEtMode.second;

	/// @todo: We are checking the maximum of slots now. We should also
	/// check WHICH slots are used. So now if modeSlots[mode] == 2
	/// we can only define 2 deviceparts, but we are not checking if
	/// both are trying to refer to the same part in fact!!
	if (modeSet.count(mode) >= params->modeSlots[mode]) {
		std::cout << mis << " card already has all the slots completed for mode " << mode << ". Max " << params->modeSlots[mode] << " slots." << std::endl;
		//std::cout << mis << " card already up for mode " << mode << std::endl;
		return -1;
	}
	modeSet.insert(mode);
	
	commonDev = s_commonMap[tn];
	*dev = commonDev;

	return NoError;
}

bool AdlDeviceFactorySingleton::release(DevicePartInterface** _dev, ADFMode mode)
{
	assert(*_dev);

	CommonDeviceInterface* commonDev = (*_dev)->common_device();
	delete (*_dev);
	return __release_common(&commonDev, mode);
}

bool AdlDeviceFactorySingleton::__release_common(CommonDeviceInterface** _dev, ADFMode mode)
{
	omni_mutex_lock lock(s_mutex);

	CommonDeviceInterface* commonDev = *_dev;
	static const char fn[] = "AdlDeviceFactorySingleton::release()";

	const AdlBoardParams* params = commonDev->type_params();
	U16 cardNum = commonDev->board_id();

	AdlDeviceFactorySingleton::CardMap & m = AdlDeviceFactorySingleton::s_cardMap;
	AdlDeviceFactorySingleton::CardTypeNumPair tn(params, cardNum);
	AdlDeviceFactorySingleton::CardMap::iterator i, e = m.end();
	i = m.find(tn);
	if (i == e) {
		std::cout << fn << " Device not defined" << std::endl;
		return false;
	}
	OpenCardMode & cardEtMode = i->second;
	OpenCardModesSet & modeSet = cardEtMode.second;
	
	if (!modeSet.count(mode)) {
		std::cout << fn << "Mode not defined for this device" << std::endl;
		return false;
	}

	modeSet.erase(mode);
	if (modeSet.size()) { // It's still registered in other modes
		*_dev = 0;
		std::cout << fn << "Device still in use by other modes" << std::endl;
		return true;
	}

	std::cout << fn << " releasing " << params->type << " " << cardNum << std::endl;
	if (params->isD2K)
		D2K_Release_Card(cardNum);
	else
		Release_Card(cardNum);

	m.erase(i);
	s_commonMap.erase(tn);

	delete commonDev;
	*_dev = 0;
	
	return true;
}
