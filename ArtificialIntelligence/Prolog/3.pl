bigger(elephant,horse).
bigger(horse,donkey).
bigger(donkey,dog).
bigger(donkey,monkey).
is_bigger(X,Y) :- bigger(X,Y),write(X), write('is bigger than '), write(Y), nl.
is_bigger(X,Y) :- bigger(X,Z), is_bigger(Z,Y).