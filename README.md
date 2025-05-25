# capteur_IR

Le but de ce projet est de concevoir un capteur de détecton de mouvement par infrarouge. Cette solution est modulable et scalable en plus de son coût de fabrication faible.

## Table des Matières

- [Description](#description)
- [Hardware](#hardware)
- [Software](#software)
- [Évolutions](#évolutions)
- [Contributeurs](#contributeurs)

## Description

Il est compsé de deux grande parties:
 - Electronique (esp32 + capteur IR LHI968)
 - Software (code C++ + dashbord avec base de données)

Ce projet a été fait par des étudiants.

## Hardware

La carte électronique est conçu pour être un sheld pour une Esp32 devkit V1.
On a utilisé KiCad pour la concevoir et generer le modèle 3d.
Et on l'a réalisé en prototypage rapide sur CNC.

Voici le schéma électronique :
![Schéma élec](hardware/CAO/schéma.png)

Et voici la réalisation final :
![rendu carte fini](hardware/3D/image.png)

![rendu 3d de la carte](hardware/3D/detec_presence_IR_2025-May-19_09-16-06AM-000_CustomizedView44217505476.png)

## Software

Ce code permet de se connecter à une base de données influxDB via une requête POST.
De notre côté on a choisi d'héberger cette base de données sur une Raspberry Pi et de l'exploiter avec Grafana.

Ce code envoi simplement la tesion du capteur toutes les 100ms à la base de données et tente une reconection au WiFi chaque fois qui pert le signal.

## Boitier

Nous avons aussi conçu un boitier pour le capteur. Il est imprimé en 3D et permet d'intégrer tous les composants de manière esthétique et fonctionnelle. (merci à BHP pour la conception du boitier)
![boitier](hardware/boitier/boitier.jpg)
![boitier ouvert](hardware/boitier/boitier_ouvert.jpg)

## Évolutions

    -[x] Remplacement du convertiseur boost par une pile 9V (ce convertiseur n'est pas recomandé)
    -[ ] Lecture de la tesion de batterie avec un pont diviseur
    -[ ] Scan des periphérique Bluethooth à proximité (distinction autorisé/non-autorisé)
    -[ ] Detection sonore, bruit ambiant
    -[ ] Camera avec integration IA (OpenCV)
    -[ ] Utiliser l'horloge temps réel de l'esp32 pour horodater les valeurs grace à un serveur de temps (plus précis)
    -[ ] Mettre en place un buffer en cas de coupure de connection pour ne pas perdre de valeurs

## Contributeurs

Ambroise Nedey-Crétaz <br />
Gaëtan Corabœuf

Sur la proposition de : <br />
M.Dumas


