#pragma once

#ifdef DLL_EXPORTS
# define INO_EXPORT __declspec(dllexport)
#else
# define INO_EXPORT __declspec(dllimport)
#endif

void INO_EXPORT print();