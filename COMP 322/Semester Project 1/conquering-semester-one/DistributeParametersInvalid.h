#include "BaseException.h"

class DistributeParametersInvalid : public BaseException {
public:
        DistributeParametersInvalid(string error);
};