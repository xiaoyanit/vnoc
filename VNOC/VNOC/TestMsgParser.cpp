
// #include <iostream>
// using namespace std; 
//extern "C"
// #include "SString.h"

//#define WIN32_LEAN_AND_MEAN

#include <iostream>
// #include <stdio.h>
//#include <Windows.h>
//#include <SUNIN/SString.h>
//#include <Wininet.h>

#include "MessageParser.h"

#pragma comment(lib,"Wininet.lib")
// #include "NetClient.h"
// #include "XmlAnalysis.h"
// #include "XmlTransform.h"
// #include <string.h>
// #include <algorithm>
// #include <assert.h>
// #include <string>
// #include <vector>
// #include <utility>
// #include <list>
// #include <set>
// #include <map>
// #include <memory>


using namespace std;

/*

NetClient netClient;
XmlAnalysis xml;*/


typedef  unsigned char   byte;	
typedef  unsigned int	 uint;



int main()
{
	byte test[] = {0x55,
		0x00,0x00,0x01,0x2B,
		0x0A,
		0x0B,
		0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,
		0x17,
		0x11,0x11,0x11,0x11,
		0x03,
		0x00,0x00,0x00,0x01,
		0x00,0x00,0x00,0x02,
		0x00,0x00,0x00,0x03,
		0x00,
		0x00,
		0x01,
		'v',
		'c',
		'd',
		0x00,0x03,
		0x43};
	byte testAVC [] = {0x55,
		0x00,0x00,0x00,0x1E,
		0x01,
		0x01,
		0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,
		0x15,
		0x00,0x00,0x00,0x00,
		0x03,
		0x00,0x00,0x00,0x04,
		0x00,0x00,0x00,0x01,
		0x00,0x00,0x00,0x10,
		0x00,0x00,0x00,0x01,
		0x01,
 		0x33,0x33,0x33,0x33,
 		0x33,0x33,0x33,0x33,
		0x33,0x33,0x33,0x33,
		0x33,0x33,0x33,0x33,
		0x00,0x05,
		0x43};
	CMessageParser msgParser;
	MSG_AVC* msg_avc = (MSG_AVC *)msgParser.Parse(testAVC);
	//cout<<msg_rvc.returnMachineAddress()<<endl;
	cout<<msg_avc->GetLoginTag()<<endl;
	cout<<msg_avc->GetType()<<endl;
	cout<<msg_avc->GetCarrier()<<endl;

	return 0;
}	



