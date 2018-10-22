#!/bin/bash
# ce programme permet de lance plusieur fois une commande pour tester la création d'un fils par un père
# Utilisation ./multiRun.sh [nb de répétitions] [commande]

if [ $# -ne 2 ]
then
    echo $0 "[nb de répétitions] [commande]"
    exit 1
fi

# définition du nombre de répétitions
MAX=$1

# séquence répétée
for X in $(seq 1 $MAX) ;
do
    $2 # commande
done