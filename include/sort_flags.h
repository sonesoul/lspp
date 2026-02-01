#pragma once
using u32 = unsigned int;

enum sort_flags : u32 {
	None		   = 0,
	Reversed	   = 1 << 1,
	DoubleReversed = 1 << 2,
	CaseSensitive  = 1 << 3,
	RecursiveSize  = 1 << 4,
};