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

However that's not the only problem. each parameter seems to have several entries, like
which one is the right one?

tabulate.
so this is not the usual meaning of arrange text in tabular form, it's a frequency-of-values exercise, in many ways, similar to the table() function in R.
Again it has to do with a strong premise on the data collecting side,
the datasets are not sanitised, we want to see how often a certain values appears for a certain variable
I'm not happy with this at all, my usual rquirement is to have the daatsets sanitised.

This lies behind the need for this crosstab struct, the one that is required before the design matrix.
the tabulate and cross tab is an effort to organize the input dataset better.

He seems to add spurious functionality to the whole thing, to make it look more beefy. Maybe, or may be not.
One aspect of categorical vars is you have to find out how many there are, and finding the frequency of each
of its values (aka. levels)

>>>> Populations as rows.
His use of populations for the rows is one of my biggest gripes, but if you look at alligators in a lake
well, in fact, you would be led to talk about the population of an alligator in a particular lake.

When you arrive at the UCLA you notice this direct variable coming up, the GRE and GPA are called direct
again yet another thing I have no idea about. 
Some of the UCLA IVs are floating point, the tabulate once again records the unique  iv combinations
and reckons how many coutns they have, which is predominantly 1.

>>> direct vs. indrect

Maarten Buis single sauthor paper "Direct and indirect effects in a logit model"
There is a variable X which has an effect on a variable Y, but part of this effect occurs through another variable Z. This indirect effect occurs because X influences Z which in turn influences Y. Within this framework, the effect of X on Y while controlling for Z is called the direct effect. 



>>> full rank center points
mentioned by him as not being covered.
