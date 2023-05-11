#pragma once

#include "stdafx.h"
#include "testing.h"
 
void writeCSVChart( const std::string& filename,
        const std::vector<double>& x,
        const std::vector<double>& y );
 
void testUsageExamples();