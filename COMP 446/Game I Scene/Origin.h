#pragma once

#include "Line.h"
#include "LineObject.h"

class Origin {
public : 
	Origin(void);
	~Origin(void);

private : 
	LineObject xLine, yLine, zLine;
};