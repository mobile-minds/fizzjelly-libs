/*

Copyright (c) 2014, Mobile Minds LTD.
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef __MM_GSMSERIAL_H__
#define __MM_GSMSERIAL_H__

#include "Arduino.h"
#include <stdint.h>
#include <stdio.h>


#ifndef GSMSERIAL_RECEIVE_BUFFERSIZE
#define GSMSERIAL_RECEIVE_BUFFERSIZE             256
#endif

#ifndef GSMSERIAL_DEFAULT_TIMEOUT
#define GSMSERIAL_DEFAULT_TIMEOUT                1000
#endif

class _GSMSerial
{
  public:
    void begin(uint32_t baudRate);
    int16_t SendCommand(const char * command, const char * waitForResponseStr=NULL, char * responseStr=NULL, int16_t responseStrSize=-1, uint32_t timeout=GSMSERIAL_DEFAULT_TIMEOUT);
    int16_t IsDataAvailable();
    int16_t Read(char * data, int16_t bufferSize, uint16_t timeout=GSMSERIAL_DEFAULT_TIMEOUT);
    void Write(const char * data, int16_t bufferSize=-1);
    void Flush();
    
  private:
    
    char ReceiveBuffer[GSMSERIAL_RECEIVE_BUFFERSIZE];
    uint16_t ReceiveBuffer_Index;
};

extern _GSMSerial GSMSerial;

#endif
