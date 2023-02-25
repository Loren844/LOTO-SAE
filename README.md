# Documentation générale du Loto  
## Principe général :
Vous allez implémenter un jeu du loto. Voici les règles qui régissent la composition d’un carton de loto : 
- Une carte contient 9 colonnes et 3 lignes. 
- Il y a sur la carte 15 numéros différents choisis parmi les nombres de 1 à 90
- Chaque ligne contient 5 numéros (et donc 4 espaces vides). 
- Il y a toujours au moins un numéro par colonne. 
- Il peut y avoir 3 numéros dans une colonne, mais seulement dans la colonne 8. 
- La colonne 0 contient les numéros de 1 à 9. 
- La colonne 1 contient les numéros de 10 à 19. 
- La colonne 2 contient les numéros de 20 à 29… 
- La colonne 7 contient les numéros de 70 à 79. 
- La colonne 8 contient les numéros de 80 à 90. 
- Une partie se décompose en 3 phases : 
    - Quine : Le premier joueur ayant recouvert une ligne de l’un de ses cartons gagne la Quine. Le joueur gagne alors 10 points, 
    - Double quine : Le premier joueur ayant recouvert 2 lignes de l’un de ses cartons gagne la double Quine. Le joueur gagne alors 20 points, 
    - Carton plein : Le premier joueur ayant recouvert l’intégralité de l’un de ses cartons gagne le Carton plein. Le joueur gagne alors 40.

## Travail demandé :
- Créer des cartons valides pour pouvoir jouer au loto. Une partie se joue avec 3 joueurs qui ont chacun un carton
- Faire jouer une partie de loto en mode console. Il ne vous est pas demandé de colorer les cases des cartons, seuls les nombres affichés dans les       cases pourront avoir une couleur différente pour les différencier plus facilement 
- Trouver comment marquer les différents états d’une case d’un carton : numéro pas encore sorti, numéro sorti et présent sur le carton
- Enregistrer l’état d’une partie si on souhaite arrêter de jouer et reprendre sa partie après. Une seule partie peut être conservée : la sauvegarde          d’une nouvelle partie écrase l’ancienne partie conservée
- Relancer une nouvelle partie. Si on veut relancer une nouvelle partie alors on ne doit pas demander à l’utilisateur s’il veut l’enregistrer
- Identifier les gagnants lors des 3 phases qui composent une partie (Quine, Double Quine et Carton plein) et afficher les scores à la fin de la              partie. 
