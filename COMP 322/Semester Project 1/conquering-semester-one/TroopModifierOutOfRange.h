#include "BaseException.h"

class TroopModifierOutOfRange : public BaseException {
public : 
        TroopModifierOutOfRange(string error);
};