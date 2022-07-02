#ifndef __EXPORT_H_
#define __EXPORT_H_

#if defined(_MSC_VER)
#ifdef SDK_SHARED
#ifdef nacos_cli_EXPORTS
#define nacos_cli_API __declspec(dllexport)
#else
#define nacos_cli_API __declspec(dllimport)
#endif
#else
#define nacos_cli_API
#endif
#else
#endif
#endif