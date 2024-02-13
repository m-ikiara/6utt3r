#ifndef _BTR_MAIN_H_
#define _BTR_MAIN_H_

#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

#include "./btr_graphics.h"
#include "./btr_controller.h"
#include "./btr_vectors.h"

#define try bool __HadError=false;
#define catch(x) ExitJmp:if(__HadError)
#define throw(x) {__HadError=true;goto ExitJmp;}

#endif // !_BTR_MAIN_H_
