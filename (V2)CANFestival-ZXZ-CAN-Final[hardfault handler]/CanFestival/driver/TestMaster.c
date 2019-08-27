
/* File generated by gen_cfile.py. Should not be modified. */

#include "TestMaster.h"

/**************************************************************************/
/* Declaration of mapped variables                                        */
/**************************************************************************/
UNS32 MasterMap1 = 0x0;		/* Mapped at index 0x2000, subindex 0x00 */
UNS32 MasterMap2 = 0x0;		/* Mapped at index 0x2001, subindex 0x00 */

/**************************************************************************/
/* Declaration of value range types                                       */
/**************************************************************************/

#define valueRange_EMC 0x9F /* Type for index 0x1003 subindex 0x00 (only set of value 0 is possible) */
UNS32 TestMaster_valueRangeTest (UNS8 typeValue, void * value)
{
  switch (typeValue) {
    case valueRange_EMC:
      if (*(UNS8*)value != (UNS8)0) return OD_VALUE_RANGE_EXCEEDED;
      break;
  }
  return 0;
}

/**************************************************************************/
/* The node id                                                            */
/**************************************************************************/
/* node_id default value.*/
UNS8 TestMaster_bDeviceNodeId = 0x00;

/**************************************************************************/
/* Array of message processing information */

const UNS8 TestMaster_iam_a_slave = 0;

TIMER_HANDLE TestMaster_heartBeatTimers[1] = {TIMER_NONE};

/*
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

                               OBJECT DICTIONARY

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/

/* index 0x1000 :   Device Type. */
                    UNS32 TestMaster_obj1000 = 0x12D;	/* 301 */
                    subindex TestMaster_Index1000[] = 
                     {
                       { RO, uint32, sizeof (UNS32), (void*)&TestMaster_obj1000 }
                     };

/* index 0x1001 :   Error Register. */
                    UNS8 TestMaster_obj1001 = 0x0;	/* 0 */
                    subindex TestMaster_Index1001[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&TestMaster_obj1001 }
                     };

/* index 0x1003 :   Pre-defined Error Field */
                    UNS8 TestMaster_highestSubIndex_obj1003 = 0; /* number of subindex - 1*/
                    UNS32 TestMaster_obj1003[] = 
                    {
                      0x0	/* 0 */
                    };
                    ODCallback_t TestMaster_Index1003_callbacks[] = 
                     {
                       NULL,
                       NULL,
                     };
                    subindex TestMaster_Index1003[] = 
                     {
                       { RW, valueRange_EMC, sizeof (UNS8), (void*)&TestMaster_highestSubIndex_obj1003 },
                       { RO, uint32, sizeof (UNS32), (void*)&TestMaster_obj1003[0] }
                     };

/* index 0x1005 :   SYNC COB ID. */
                    UNS32 TestMaster_obj1005 = 0x40000080;	/* 1073741952 */
                    ODCallback_t TestMaster_Index1005_callbacks[] = 
                     {
                       NULL,
                     };
                    subindex TestMaster_Index1005[] = 
                     {
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1005 }
                     };

/* index 0x1006 :   Communication / Cycle Period. */
                    UNS32 TestMaster_obj1006 = 0xC350;	/* 50000 */
                    ODCallback_t TestMaster_Index1006_callbacks[] = 
                     {
                       NULL,
                     };
                    subindex TestMaster_Index1006[] = 
                     {
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1006 }
                     };

/* index 0x100C :   Guard Time */ 
                    UNS16 TestMaster_obj100C = 0x0;   /* 0 */

/* index 0x100D :   Life Time Factor */ 
                    UNS8 TestMaster_obj100D = 0x0;   /* 0 */

/* index 0x1010 :   Store parameters. */
                    UNS8 TestMaster_highestSubIndex_obj1010 = 4; /* number of subindex - 1*/
                    UNS32 TestMaster_obj1010_Save_All_Parameters = 0x0;	/* 0 */
                    UNS32 TestMaster_obj1010_Save_Communication_Parameters = 0x0;	/* 0 */
                    UNS32 TestMaster_obj1010_Save_Application_Parameters = 0x0;	/* 0 */
                    UNS32 TestMaster_obj1010_Save_Manufacturer_Parameters_1 = 0x0;	/* 0 */
                    subindex TestMaster_Index1010[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&TestMaster_highestSubIndex_obj1010 },
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1010_Save_All_Parameters },
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1010_Save_Communication_Parameters },
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1010_Save_Application_Parameters },
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1010_Save_Manufacturer_Parameters_1 }
                     };

/* index 0x1011 :   Restore Default Parameters. */
                    UNS8 TestMaster_highestSubIndex_obj1011 = 4; /* number of subindex - 1*/
                    UNS32 TestMaster_obj1011_Restore_All_Default_Parameters = 0x0;	/* 0 */
                    UNS32 TestMaster_obj1011_Restore_Communication_Default_Parameters = 0x0;	/* 0 */
                    UNS32 TestMaster_obj1011_Restore_Application_Default_Parameters = 0x0;	/* 0 */
                    UNS32 TestMaster_obj1011_Restore_Manufacturer_Defined_Default_Parameters_1 = 0x0;	/* 0 */
                    subindex TestMaster_Index1011[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&TestMaster_highestSubIndex_obj1011 },
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1011_Restore_All_Default_Parameters },
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1011_Restore_Communication_Default_Parameters },
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1011_Restore_Application_Default_Parameters },
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1011_Restore_Manufacturer_Defined_Default_Parameters_1 }
                     };

/* index 0x1014 :   Emergency COB ID. */
                    UNS32 TestMaster_obj1014 = 0x80;	/* 128 */
                    subindex TestMaster_Index1014[] = 
                     {
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1014 }
                     };

/* index 0x1016 :   Consumer Heartbeat Time. */
                    UNS8 TestMaster_highestSubIndex_obj1016 = 1; /* number of subindex - 1*/
                    UNS32 TestMaster_obj1016[] = 
                    {
                      0x205DC	/* 132572 */
                    };
                    subindex TestMaster_Index1016[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&TestMaster_highestSubIndex_obj1016 },
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1016[0] }
                     };

/* index 0x1017 :   Producer Heartbeat Time */ 
                    UNS16 TestMaster_obj1017 = 0x0;   /* 0 */

/* index 0x1018 :   Identity. */
                    UNS8 TestMaster_highestSubIndex_obj1018 = 4; /* number of subindex - 1*/
                    UNS32 TestMaster_obj1018_Vendor_ID = 0x0;	/* 0 */
                    UNS32 TestMaster_obj1018_Product_Code = 0x0;	/* 0 */
                    UNS32 TestMaster_obj1018_Revision_Number = 0x0;	/* 0 */
                    UNS32 TestMaster_obj1018_Serial_Number = 0x0;	/* 0 */
                    subindex TestMaster_Index1018[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&TestMaster_highestSubIndex_obj1018 },
                       { RO, uint32, sizeof (UNS32), (void*)&TestMaster_obj1018_Vendor_ID },
                       { RO, uint32, sizeof (UNS32), (void*)&TestMaster_obj1018_Product_Code },
                       { RO, uint32, sizeof (UNS32), (void*)&TestMaster_obj1018_Revision_Number },
                       { RO, uint32, sizeof (UNS32), (void*)&TestMaster_obj1018_Serial_Number }
                     };

/* index 0x1280 :   Client SDO 1 Parameter. */
                    UNS8 TestMaster_highestSubIndex_obj1280 = 3; /* number of subindex - 1*/
                    UNS32 TestMaster_obj1280_COB_ID_Client_to_Server_Transmit_SDO = 0x602;	/* 1538 */
                    UNS32 TestMaster_obj1280_COB_ID_Server_to_Client_Receive_SDO = 0x582;	/* 1410 */
                    UNS8 TestMaster_obj1280_Node_ID_of_the_SDO_Server = 0x2;	/* 2 */
                    subindex TestMaster_Index1280[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&TestMaster_highestSubIndex_obj1280 },
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1280_COB_ID_Client_to_Server_Transmit_SDO },
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1280_COB_ID_Server_to_Client_Receive_SDO },
                       { RW, uint8, sizeof (UNS8), (void*)&TestMaster_obj1280_Node_ID_of_the_SDO_Server }
                     };

/* index 0x1400 :   Receive PDO 1 Parameter. */
                    UNS8 TestMaster_highestSubIndex_obj1400 = 5; /* number of subindex - 1*/
                    UNS32 TestMaster_obj1400_COB_ID_used_by_PDO = 0x200;	/* 512 */
                    UNS8 TestMaster_obj1400_Transmission_Type = 0x1;	/* 1 */
                    UNS16 TestMaster_obj1400_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 TestMaster_obj1400_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 TestMaster_obj1400_Event_Timer = 0x0;	/* 0 */
                    subindex TestMaster_Index1400[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&TestMaster_highestSubIndex_obj1400 },
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1400_COB_ID_used_by_PDO },
                       { RW, uint8, sizeof (UNS8), (void*)&TestMaster_obj1400_Transmission_Type },
                       { RW, uint16, sizeof (UNS16), (void*)&TestMaster_obj1400_Inhibit_Time },
                       { RW, uint8, sizeof (UNS8), (void*)&TestMaster_obj1400_Compatibility_Entry },
                       { RW, uint16, sizeof (UNS16), (void*)&TestMaster_obj1400_Event_Timer }
                     };

/* index 0x1600 :   Receive PDO 1 Mapping. */
                    UNS8 TestMaster_highestSubIndex_obj1600 = 2; /* number of subindex - 1*/
                    UNS32 TestMaster_obj1600[] = 
                    {
                      0x20000020,	/* 536870944 */
                      0x20010020	/* 536936480 */
                    };
                    subindex TestMaster_Index1600[] = 
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&TestMaster_highestSubIndex_obj1600 },
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1600[0] },
                       { RW, uint32, sizeof (UNS32), (void*)&TestMaster_obj1600[1] }
                     };

/* index 0x1F22 :   Concise DCF. */
                    UNS8 TestMaster_highestSubIndex_obj1F22 = 2; /* number of subindex - 1*/
                    UNS8* TestMaster_obj1F22[] = 
                    {
                      "",
                      "\x01\x00\x00\x00\x17\x10\x00\x02\x00\x00\x00\xe8\x03"
                    };
                    subindex TestMaster_Index1F22[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&TestMaster_highestSubIndex_obj1F22 },
                       { RW, domain, 0, (void*)&TestMaster_obj1F22[0] },
                       { RW, domain, 13, (void*)&TestMaster_obj1F22[1] }
                     };

/* index 0x2000 :   Mapped variable MasterMap1 */
                    ODCallback_t MasterMap1_callbacks[] = 
                     {
                       NULL,
                     };
                    subindex TestMaster_Index2000[] = 
                     {
                       { RW, uint32, sizeof (UNS32), (void*)&MasterMap1 }
                     };

/* index 0x2001 :   Mapped variable MasterMap2 */
                    subindex TestMaster_Index2001[] = 
                     {
                       { RW, uint32, sizeof (UNS32), (void*)&MasterMap2 }
                     };

/**************************************************************************/
/* Declaration of pointed variables                                       */
/**************************************************************************/

const indextable TestMaster_objdict[] = 
{
  { (subindex*)TestMaster_Index1000,sizeof(TestMaster_Index1000)/sizeof(TestMaster_Index1000[0]), 0x1000},
  { (subindex*)TestMaster_Index1001,sizeof(TestMaster_Index1001)/sizeof(TestMaster_Index1001[0]), 0x1001},
  { (subindex*)TestMaster_Index1005,sizeof(TestMaster_Index1005)/sizeof(TestMaster_Index1005[0]), 0x1005},
  { (subindex*)TestMaster_Index1006,sizeof(TestMaster_Index1006)/sizeof(TestMaster_Index1006[0]), 0x1006},
  { (subindex*)TestMaster_Index1010,sizeof(TestMaster_Index1010)/sizeof(TestMaster_Index1010[0]), 0x1010},
  { (subindex*)TestMaster_Index1011,sizeof(TestMaster_Index1011)/sizeof(TestMaster_Index1011[0]), 0x1011},
  { (subindex*)TestMaster_Index1014,sizeof(TestMaster_Index1014)/sizeof(TestMaster_Index1014[0]), 0x1014},
  { (subindex*)TestMaster_Index1016,sizeof(TestMaster_Index1016)/sizeof(TestMaster_Index1016[0]), 0x1016},
  { (subindex*)TestMaster_Index1018,sizeof(TestMaster_Index1018)/sizeof(TestMaster_Index1018[0]), 0x1018},
  { (subindex*)TestMaster_Index1280,sizeof(TestMaster_Index1280)/sizeof(TestMaster_Index1280[0]), 0x1280},
  { (subindex*)TestMaster_Index1400,sizeof(TestMaster_Index1400)/sizeof(TestMaster_Index1400[0]), 0x1400},
  { (subindex*)TestMaster_Index1600,sizeof(TestMaster_Index1600)/sizeof(TestMaster_Index1600[0]), 0x1600},
  { (subindex*)TestMaster_Index1F22,sizeof(TestMaster_Index1F22)/sizeof(TestMaster_Index1F22[0]), 0x1F22},
  { (subindex*)TestMaster_Index2000,sizeof(TestMaster_Index2000)/sizeof(TestMaster_Index2000[0]), 0x2000},
  { (subindex*)TestMaster_Index2001,sizeof(TestMaster_Index2001)/sizeof(TestMaster_Index2001[0]), 0x2001},
};

const indextable * TestMaster_scanIndexOD (UNS16 wIndex, UNS32 * errorCode, ODCallback_t **callbacks)
{
	int i;
	*callbacks = NULL;
	switch(wIndex){
		case 0x1000: i = 0;break;
		case 0x1001: i = 1;break;
		case 0x1005: i = 2;*callbacks = TestMaster_Index1005_callbacks; break;
		case 0x1006: i = 3;*callbacks = TestMaster_Index1006_callbacks; break;
		case 0x1010: i = 4;break;
		case 0x1011: i = 5;break;
		case 0x1014: i = 6;break;
		case 0x1016: i = 7;break;
		case 0x1018: i = 8;break;
		case 0x1280: i = 9;break;
		case 0x1400: i = 10;break;
		case 0x1600: i = 11;break;
		case 0x1F22: i = 12;break;
		case 0x2000: i = 13;*callbacks = MasterMap1_callbacks; break;
		case 0x2001: i = 14;break;
		default:
			*errorCode = OD_NO_SUCH_OBJECT;
			return NULL;
	}
	*errorCode = OD_SUCCESSFUL;
	return &TestMaster_objdict[i];
}

/* 
 * To count at which received SYNC a PDO must be sent.
 * Even if no pdoTransmit are defined, at least one entry is computed
 * for compilations issues.
 */
s_PDO_status TestMaster_PDO_status[1] = {s_PDO_status_Initializer};

const quick_index TestMaster_firstIndex = {
  0, /* SDO_SVR */
  9, /* SDO_CLT */
  10, /* PDO_RCV */
  11, /* PDO_RCV_MAP */
  0, /* PDO_TRS */
  0 /* PDO_TRS_MAP */
};

const quick_index TestMaster_lastIndex = {
  0, /* SDO_SVR */
  9, /* SDO_CLT */
  10, /* PDO_RCV */
  11, /* PDO_RCV_MAP */
  0, /* PDO_TRS */
  0 /* PDO_TRS_MAP */
};

const UNS16 TestMaster_ObjdictSize = sizeof(TestMaster_objdict)/sizeof(TestMaster_objdict[0]); 

CO_Data TestMaster_Data = CANOPEN_NODE_DATA_INITIALIZER(TestMaster);
