# QuentinsLib

> Cette librairie contient des fonctions et procédures nécessaires à la réalisation de tâches simples mais souvent répétitives

# Table des matières

1. [Importer et utiliser la librairie](#use_library)

## Utiliser la librairie QuentinsLib.lib <a name="use_library"></a>

> Cette section décrit les étapes à suivre pour utiliser la librairie sans problème de compilation.

> 1 : `Clic droit` sur le projet dans `l'explorateur de solution`

> 2 : Sélectionner `Propritétés` dans le menu déroulant

> 3 : Dans l'onglet `Propriétés de configuration -> C/C++ -> Général` allez chercher la ligne `Autres répertoires include`, cliquez sur la flèche, `modifier`

> 4 : Ici, remplacer `C:\Users\....\QuentinsLib\QuentinsLib` par `Chemin_Vers_Le_Téléchargement\QuentinsLib\QuentinsLib`

![Recordit GIF](http://recordit.co/f4vnlUbbMp.gif)

> 5 : Dans l'onglet `Propriétés de configuration -> Éditeur de liens -> Général` allez chercher le ligne `Répertoires de bibliothèques supplémentaires`, cliquez sur la flèche, `modifier`

> 6 : Ici, remplacer `C:\Users\....\QuentinsLib\x64\Debug\` par `Chemin_Vers_Le_Téléchargement\QuentinsLib\x64\Debug`

![Recordit GIF](http://recordit.co/suPAP77Xce.gif)

> 7 : Dans l'onglet `Propriétés de configuration -> Éditeur de liens -> entrée` allez chercher le ligne `Dépendances supplémentaires`, cliquez sur la flèche puis tapez `QuentinsLib.lib`

![Recordit GIF](http://recordit.co/6cznfMh6mx.gif)