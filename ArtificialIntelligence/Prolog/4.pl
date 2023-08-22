blond(X):-
    father(Father,X),
    mother(Mother,X),
    blond(Father),
    blond(Mother).

father(zahid,amjad).
mother(zahida, amjad).
blond(zahid).
blond(zahida).
father(akbar,asghar).
mother(akbari,asghar).
blond(akbar).
blond(akbari).
father(rehan,rashid).
mother(rehana,rashid).
blond(rehan).
blond(rehana).

