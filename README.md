# 2048-tile-twister

Simple Tile Twister game in C++

In case you encounter error "build.sh" appear and you're on windows, launch this command to go from CRLF to LF (command on git bash!)

```bash
dos2unix build.sh
```

Create executable :

```bash
docker compose up windows --build
```

Execute executable

```bash
./build/2048.exe
```

<div align="center">

![2048](img/2048_win.png)

# 🎮 2048 - Tile Twister

### Un clone moderne du célèbre jeu 2048

[![C++](https://img.shields.io/badge/C++-17-blue.svg?style=for-the-badge&logo=c%2B%2B)](https://isocpp.org/)
[![SDL3](https://img.shields.io/badge/SDL-3.0-orange.svg?style=for-the-badge&logo=sdl)](https://www.libsdl.org/)
[![CMake](https://img.shields.io/badge/CMake-3.15+-064F8C.svg?style=for-the-badge&logo=cmake)](https://cmake.org/)
[![Docker](https://img.shields.io/badge/Docker-Ready-2496ED.svg?style=for-the-badge&logo=docker&logoColor=white)](https://www.docker.com/)

[Installation](#-installation) •
[Utilisation](#-utilisation) •
[Architecture](#-architecture) •
[Roadmap](#-roadmap)

![Gameplay](https://via.placeholder.com/600x400/667eea/ffffff?text=2048+Screenshot)

</div>

---

## ✨ Fonctionnalités

- 🎯 **Grille 4x4 classique** - Le jeu original fidèlement reproduit
- ⌨️ **Contrôles intuitifs** - Touches directionnelles pour jouer
- 🎨 **Interface SDL3** - Rendu fluide et moderne
- 🏆 **Détection victoire/défaite** - Messages d'état en temps réel
- 🐳 **Docker ready** - Compilation cross-platform simplifiée
- 🪟 **Support Windows** - Build MinGW natif

## 🚀 Installation

### Prérequis

```bash
- Docker & Docker Compose
- CMake 3.15+
- SDL3 + SDL3_ttf
```

### Compilation rapide

```bash
# Cloner le repository
git clone https://github.com/votre-username/2048-tile-twister.git
cd 2048-tile-twister

# Build avec Docker
docker-compose up

# L'exécutable est généré dans ./build/
```

## 🎮 Utilisation

### Lancer le jeu

```bash
./build/2048
```

### Contrôles

| Touche | Action                    |
| ------ | ------------------------- |
| ⬆️ `↑` | Déplacer vers le haut     |
| ⬇️ `↓` | Déplacer vers le bas      |
| ⬅️ `←` | Déplacer vers la gauche   |
| ➡️ `→` | Déplacer vers la droite   |
| 🔄 `R` | Rejouer / Nouvelle partie |
| `ESC`  | Quitter                   |

### Règles du jeu

1. Utilisez les flèches directionnelles pour déplacer les tuiles
2. Les tuiles identiques fusionnent quand elles se touchent
3. Créez une tuile **2048** pour gagner ! 🎉
4. Plus de mouvements possibles = défaite 😢

## 📁 Architecture

```
2048-tile-twister/
├── 📂 src/
│   ├── 📂 core/           # Logique métier
│   │   ├── game.cpp       # Gestionnaire de jeu
│   │   ├── grid.cpp       # Grille de jeu
│   │   └── tile.cpp       # Tuiles individuelles
│   ├── 📂 views/          # Interface graphique
│   │   ├── window.cpp     # Fenêtre principale
│   │   ├── gridView.cpp   # Rendu de la grille
│   │   └── tileView.cpp   # Rendu des tuiles
│   └── main.cpp           # Point d'entrée
├── 📂 assets/
│   └── Roboto-Bold.ttf    # Police d'affichage
├── 🐳 Dockerfile
├── 📝 CMakeLists.txt
└── 📖 README.md
```

### Design Pattern

- **MVC** : Séparation core/views
- **Composition** : GameObject → TileView/GridView
- **Encapsulation** : Grid gère les Tiles

## 🛠️ Technologies

<div align="center">

| Technologie  | Usage                  |
| ------------ | ---------------------- |
| **C++17**    | Langage principal      |
| **SDL3**     | Rendu graphique        |
| **SDL3_ttf** | Affichage texte        |
| **CMake**    | Build system           |
| **Docker**   | Environnement de build |

</div>

## 📊 Roadmap

- [x] Grille 4x4 fonctionnelle
- [x] Mouvements et fusions
- [x] Détection victoire (2048)
- [x] Détection défaite (plus de mouvements)
- [x] Affichage messages de fin
- [ ] 🎯 Bouton "Rejouer"
- [ ] 💾 Sauvegarde du meilleur score
- [ ] 🎨 Thèmes de couleurs
- [ ] 🔊 Effets sonores
- [ ] 📱 Version mobile

## 🤝 Contribution

Les contributions sont les bienvenues ! N'hésitez pas à :

1. 🍴 Fork le projet
2. 🔨 Créer une branche (`git checkout -b feature/AmazingFeature`)
3. 💾 Commit vos changements (`git commit -m 'Add AmazingFeature'`)
4. 📤 Push vers la branche (`git push origin feature/AmazingFeature`)
5. 🎉 Ouvrir une Pull Request

## 📝 Licence

Distribué sous licence MIT. Voir `LICENSE` pour plus d'informations.

## 👤Contributing

This project was made by:

- [Thibault Caron](https://github.com/thibault-caron)
- [Adeline Patenne](https://github.com/AdelinePat/)
- [Florence Navet](https://github.com/florence-navet)

---

<div align="center">

![2048_loose](img/2048_loose.png)

</div>
