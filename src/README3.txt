The "main"
is all about the values for the 3 or 4 options, reading them from argument line
that's all it does, pretty much.

csvgetline is the workhorse of the dset reader.

the program has a system of internal commands which are executed according to the schedule file (option -f)
the functions for these are names cmd_etc()

I've imposed my style of naming structs with a _t at the end
standing of course for "type", his was a litle indistinct. COMMAND in caps? Not great.

"dataspace" allows for more than 1 dataset, mdsets perhaps?

in introducing the typedef dataset, to which I add a _t, he says
    A basic abstraction for storing and accessing data and metadata.
Abstraction? Why such florid language for a mere datastruct? Not merited.

"weight", I have not been so used to this type of variable but ut basically allows a weighting
for one observation of an input dataset
in the allig dset, some times a few or even 0 alligs are recorded
It seems silly to record an observation with 0 importance, but I admit it facilitates the data collector somewhat.
Essentially it records a potential observation, but one that yielded zero obs.


I was looking at the verbose output and wondering where the betas are. 
they appear at the end sure, but disguised as:

Maximum Likelihood Parameter Estimates
=======================================

so this badly done. the label looks as if it's about the inner workings for the ML, it's not.
these are the betas. of course i@m goign to change that.

