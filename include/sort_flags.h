#pragma once
using u32 = unsigned int;

enum lspp_flag : u32 {
	None		   = 0,
	Reversed	   = 1 << 1,
	TypeReversed   = 1 << 2,
	CaseSensitive  = 1 << 3,
	RecursiveSize  = 1 << 4,
};