/***************************************************************
 * Name:      FexWrite.h
 * Purpose:   Extract and write the descriptors according to the input parameters
 * Author:    Muhammet Bastan (bastan@cs.bilkent.edu.tr)
 * Created:   31.10.2009
 * Copyright: Muhammet Bastan (http://www.cs.bilkent.edu.tr/~bastan)
 * License:
 **************************************************************/
#ifndef FEXWRITE_H_INCLUDED
#define FEXWRITE_H_INCLUDED

#include "Feature.h"

class FexWrite
{
    public:

        /// Color
        static void computeWriteCSD(Frame *frame, std::ofstream & fout, int descSize = 64);
        static void computeWriteSCD( Frame* frame, std::ofstream & fout, bool maskFlag = true, int descSize = 128 );
        static void computeWriteCLD( Frame* frame, std::ofstream & fout, int numYCoef = 64, int numCCoef = 28 );
        static void computeWriteDCD( Frame* frame, std::ofstream & fout,
                                bool normalize = true, bool variance = true, bool spatial = true,
                                int bin1 = 32, int bin2 = 32, int bin3 = 32 );
        /// Texture
        static void computeWriteHTD( Frame* frame, std::ofstream & fout, int layerFlag = 1 );
        static void computeWriteEHD( Frame* frame, std::ofstream & fout);

        /// shape
        static void computeWriteRSD( Frame* frame );
        static void computeWriteCShD( Frame* frame );
};

#endif
