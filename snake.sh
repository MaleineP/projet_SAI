#!/bin/bash

make clean
sleep 1
echo -e "\n\tCompilation ..."
make
echo -e "\n\tContrôles du jeu : Q et D pour changer de direction"
echo -e "\n\t  Z pour passer en vue en première personne"
echo -e "\n\t  S pour passer en vue en troisième personne"
echo -e "\n\t  X pour tirer droit devant soi"
echo -e "\n\nAppuyez sur une touche pour continuer et jouer..."
read a
./snake
echo -e "\n"
make clean