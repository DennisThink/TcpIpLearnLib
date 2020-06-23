#include "NetProtoPrint.h"
std::string UnsignedCharToHex(const unsigned char ch)
{
    const char buf[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char result[3]={0};
    result[0]=buf[ch/16];
    result[1]=buf[ch%16];
    return std::string(result);
}

std::string MacAddrToString(const MacAddrHeader& header)
{
    std::string strResult;
    {
        std::string strSrc;
        for(int i = 0 ; i < 5 ; i++)
        {
            strSrc += UnsignedCharToHex(header.mSrcMacAddr[i]);
            strSrc += "-";
        }
        strSrc += UnsignedCharToHex(header.mSrcMacAddr[5]);

        strResult = "SourceMac: "+strSrc;
    }

    {
        std::string strDst;
        for(int i = 0 ; i < 5 ; i++)
        {
            strDst += UnsignedCharToHex(header.mDestMacAddr[i]);
            strDst += "-";
        }
        strDst += UnsignedCharToHex(header.mDestMacAddr[5]);

        strResult = strResult +" DestMac: "+strDst;
    }

	//
    {
		if (header.m_type == 0x0800)
		{
			strResult += " Type: IPV4 Frame";
		}
		else if(header.m_type == 0x0806)
		{
			strResult += " Type: ARP Frame";
		}
		else if (header.m_type == 0x8035)
		{
			strResult += " Type: RARP Frame";
		}
		else if (header.m_type == 0x86DD)
		{
			strResult += " Type: IPV6 Frame";
		}
		else if (header.m_type == 0x8006)
		{
			strResult += " Type: Nestar Frame";
		}
		else
		{
			std::string strType = " Type: " + std::to_string(header.m_type);
			strResult += strType;
		}
    }
    return strResult;
}