# lspp

lspp is a CLI program that shows directory contents, including files, directories, etc.. It is also can be used for file size analysis which can be way faster than doing it on your own. 
Simply call `lspp` from your terminal and it will show you the state of current directory, which can be changed by [giving arguments](Arguments).

## Arguments
The program has various arguments that can be given, and they all have shortened version.

Reverse sorting order  
`-reversed` `-rv`  

Sort entries by name (case-sensitive)  
`--by-name-cs` `-cs`

Sort entries by name (case-insensitive)  
`--by-name-ci` `-ci`    

Sort entries by file size  
`--by-size` `-sz`  

Disable size measurement  
`--no-measure` `-nm`  

Measure directory sizes recursively  
`-recursive` `-rc`  

Show files before directories  
`--file-first` `-ff`  

Show directories before files  
`--dir-first` `-df`  

Do not prioritize files or directories  
`--no-priority` `-np`  
