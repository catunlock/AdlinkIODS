static const char *RcsId = "$Header$";
//+=============================================================================
//
// file :         AdlinkAIOStateMachine.cpp
//
// description :  C++ source for the AdlinkAIO and its alowed. 
//                method for commands and attributes
//
// project :      TANGO Device Server
//
// $Author: rsune $
//
// $Revision: 8649 $
//
//
//
// copyleft :   CELLS/ALBA
//		Edifici Ciences Nord
//		Campus Universitari de Bellaterra
//		Universitat Autonoma de Barcelona
//		08193 Bellaterra, Barcelona, SPAIN
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//=============================================================================

#include <tango.h>
#include <AdlinkAIO.h>
#include <AdlinkAIOClass.h>

#define __YES_READ if (type==Tango::READ_REQ) return true;
#define __NO_(mode) if(get_state() == Tango:: mode) return false;
#define __YES_(mode) if(get_state() == Tango:: mode) return true;
#define __NO_BAD __NO_(FAULT) __NO_(UNKNOWN)
#define __YES_ANY return true;
#define __NO_ANY return false;

/*====================================================================
 *	This file contains the methods to allow commands and attributes
 * read or write execution.
 *
 * If you wand to add your own code, add it between 
 * the "End/Re-Start of Generated Code" comments.
 *
 * If you want, you can also add your own methods.
 *====================================================================
 */

namespace AdlinkAIO_ns
{

//=================================================
//		Attributes Allowed Methods
//=================================================

//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_SpectrumStatistic_allowed
//
// description : 	Read/Write allowed for SpectrumStatistic attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_SpectrumStatistic_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_ScalarStatistic_allowed
//
// description : 	Read/Write allowed for ScalarStatistic attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_ScalarStatistic_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_ScalarValue_allowed
// 
// description : 	Read/Write allowed for ScalarValue attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_ScalarValue_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_ChannelSpectrum_allowed
// 
// description : 	Read/Write allowed for ChannelSpectrum attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_ChannelSpectrum_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_Delay_allowed
// 
// description : 	Read/Write allowed for Delay attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_Delay_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_DelaySource_allowed
//
// description : 	Read/Write allowed for DelaySource attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_DelaySource_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN       ||
		get_state() == Tango::ON        ||
		get_state() == Tango::RUNNING   ||
		get_state() == Tango::FAULT)
	{
		//      End of Generated Code
		__NO_BAD;
		__YES_READ
		//      Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_SampleRate_allowed
// 
// description : 	Read/Write allowed for SampleRate attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_SampleRate_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_ChannelSamplesPerTrigger_allowed
// 
// description : 	Read/Write allowed for ChannelSamplesPerTrigger attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_ChannelSamplesPerTrigger_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_NumOfTriggers_allowed
// 
// description : 	Read/Write allowed for NumOfTriggers attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_NumOfTriggers_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_NumOfTriggers_allowed
//
// description : 	Read/Write allowed for NumOfDisplayableTriggers attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_NumOfDisplayableTriggers_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_MaxRefSource_allowed
// 
// description : 	Read/Write allowed for MaxRefSource attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_MaxRefSource_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_MinRefSource_allowed
// 
// description : 	Read/Write allowed for MinRefSource attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_MinRefSource_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_TriggerHighLimit_allowed
// 
// description : 	Read/Write allowed for TriggerHighLimit attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_TriggerHighLimit_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_TriggerLowLimit_allowed
// 
// description : 	Read/Write allowed for TriggerLowLimit attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_TriggerLowLimit_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_TriggerSources_allowed
// 
// description : 	Read/Write allowed for TriggerSources attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_TriggerSources_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_TriggerMode_allowed
// 
// description : 	Read/Write allowed for TriggerMode attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_TriggerMode_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_TriggerInfinite_allowed
// 
// description : 	Read/Write allowed for TriggerInfinite attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_TriggerInfinite_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_BufferPeriod_allowed
// 
// description : 	Read/Write allowed for BufferPeriod attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_BufferPeriod_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_BufferedChannelsList_allowed
// 
// description : 	Read/Write allowed for BufferedChannelsList attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_BufferedChannelsList_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::STANDBY	||
		get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		__YES_(STANDBY);
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_RawDATA_allowed
// 
// description : 	Read/Write allowed for RawDATA attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_RawDATA_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_DoubleDATA_allowed
// 
// description : 	Read/Write allowed for DoubleDATA attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_DoubleDATA_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_FileName_allowed
// 
// description : 	Read/Write allowed for FileName attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_FileName_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}

//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_LastValues_allowed
// 
// description : 	Read/Write allowed for LastValues attribute.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_LastValues_allowed(Tango::AttReqType type)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code
		__NO_BAD;
		__YES_READ;
		//	Re-Start of Generated Code
		return false;
	}
	return true;
}

//=================================================
//		Commands Allowed Methods
//=================================================

//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_Start_allowed
// 
// description : 	Execution allowed for Start command.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_Start_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::RUNNING	||
		get_state() == Tango::FAULT)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_Stop_allowed
// 
// description : 	Execution allowed for Stop command.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_Stop_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::STANDBY)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_ImportFile_allowed
// 
// description : 	Execution allowed for ImportFile command.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_ImportFile_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_CalibrationAuto_allowed
// 
// description : 	Execution allowed for CalibrationAuto command.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_CalibrationAuto_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::FAULT	||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	if (get_state() != Tango::STANDBY)
		return false;
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_CalibrationSave_allowed
// 
// description : 	Execution allowed for CalibrationSave command.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_CalibrationSave_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::UNKNOWN	||
		   get_state() == Tango::FAULT	||
		   get_state() == Tango::ON	||
		   get_state() == Tango::RUNNING)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	if (get_state() != Tango::STANDBY)
		return false;
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_CalibrationLoad_allowed
// 
// description : 	Execution allowed for CalibrationLoad command.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_CalibrationLoad_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::UNKNOWN	||
		   get_state() == Tango::FAULT	||
		   get_state() == Tango::ON	||
		   get_state() == Tango::RUNNING)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	if (get_state() != Tango::STANDBY)
		return false;
	return true;
}
//+----------------------------------------------------------------------------
//
// method : 		AdlinkAIO::is_ExportFile_allowed
// 
// description : 	Execution allowed for ExportFile command.
//
//-----------------------------------------------------------------------------
bool AdlinkAIO::is_ExportFile_allowed(const CORBA::Any &any)
{
	if (get_state() == Tango::UNKNOWN	||
		get_state() == Tango::FAULT	/*||
		get_state() == Tango::ON	||
		get_state() == Tango::RUNNING*/)
	{
		//	End of Generated Code

		//	Re-Start of Generated Code
		return false;
	}
	return true;
}

}	// namespace AdlinkAIO_ns
