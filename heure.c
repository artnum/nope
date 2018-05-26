/* 
 * Implementation of https://www.desmos.com/calculator/9wczoeqvjd by
 * Benoît Müller.
 * -> "Compression" of hours within a range
 *
 * Copyright 2018 Etienne Bagnoud <etienne@artisan-numerique.ch>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *     Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float sgn ( float x ) {
    return (x > 0) - (x < 0);
}

float f( float x ) {
    float a = 0, b = 0, c = 0;

    a = ((1 - sgn(x * ( x - 7))) / 2) * x;
    b = ((1 - sgn(( x - 7 ) * ( x - 17 ))) / 2) * ( (3 * x) - 14 );
    c = ((1 - sgn((x - 17) * (x - 24))) /2) * ( x + 20 ) * sgn(fabsf(x - 24));
    
    return a + b + c;
}

float fbis ( float x, float r[2] ) {
    float a = 0, b = 0, c = 0, dr = fabsf(r[0] - r[1]);

    a = ((1 - sgn(x * ( x - r[0]))) / 2) * x;
    b = ((1 - sgn(( x - r[0] ) * ( x - r[1] ))) / 2) * ( (3 * x) - (24 - dr) );
    c = ((1 - sgn((x - r[1]) * (x - 24))) /2) * ( x + (dr * 2) ) * sgn(fabsf(x - 24));
    
    return a + b + c;

}

int main ( int argc, char ** argv ) {
    float i = 0, range[2] = { 7, 17 };

    for(i = 0; i < 24; i+=0.5) {
        printf("%f -> %f -> %f\n", i, f(i), fbis(i, range));
    }


    return 0;
}
