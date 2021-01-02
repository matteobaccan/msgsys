::
:: Demo with error
::
clipper demo /n
::rtlink fi demo,msgita
blinker fi demo,msgita bli inc off nob bli exe nob bli exe com 1

::
:: Demo without error
::
clipper demo /n
clipper getsys /n
::rtlink fi demo,msgita,getsys out demook
blinker fi demo,msgita,getsys out demook bli inc off nob bli exe nob bli exe com 1

::
:: Demo without error with debugger
::
clipper demo /n/b
clipper getsys /n/b
::rtlink fi demo,msgita,getsys out demook
blinker fi demo,msgita,getsys out demodbg bli exe ext sea blxclp52 fi cld.lib bli inc off nob bli exe com 1
