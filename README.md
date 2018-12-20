# Guerledan_Sailboat
Pour ce projet Github, nous allons recoder la partie Contrôleur du voilier autonome. L'architecture globale du projet est la suivante:

Variables.cpp ( Basé sur Globals.cpp de UxVCtrl pour la gestion de toutes les variables du projet)

WhichController.cpp ( Définissant quel contrôleur doit être utilisé en fonction du respect de la zone de sécurité et permet de parser les fichiers missions ainsi que les fichiers de configuration)(Abbas)

En fonction de WhichController.cpp, on utilise soit Controller.cpp ( Code de M.Le Bars) ou OurController.cpp :


Dans OurController.cpp (Alexandre), on retrouve:

WindEstimator.cpp : Permet de connaître la direction du vent apparent via Machine Learning (Alexandre)


PositionEstimator.cpp : Permet de déterminer la position du bateau et de s'assurer que nous suivions bien l'itinéraire voulu par SLAM ( Abbas & Elodie)

DetectBall.cpp ( Basé sur Ball.cpp de UxVCtrl) Permet de détecter la balle et de connaître sa position ( Elodie)


WhichWay.cpp : Basé sur la théorie des graphes, permet de savoir quel chemin prendre pour passer de bouée en bouée. ( Elodie)




A cote de ça, sont codés les fichiers :


Sécurité.cpp (Elodie): qui définit le périmètre de sécurité à respecter en fonction des fichiers de configuration et vérifie aussi les variables estimées en fonction des capteurs.


Les fichiers de configuration contenant les missions, le polygone de la zone de sécurité, la position des bouées en GPS et les tolérances de sécurité.


Reporter.cpp : permettant de logger les variables utiles sous format .csv comme les log de UxVCtrl





LES NOMS SONT SUJETS A MODIFICATION
