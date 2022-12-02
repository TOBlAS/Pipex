# Pipex
## Ce projet est la découverte en détails et par la programmation d’un mécanisme UNIX que vous connaissez déjà.

Le projet a pour but de reproduire le comportement Shell des pipes ( | ) en C.

Il nous mène à la découverte de nouvelles fonctions telles que :

> fork(), 
> dup2(), 
> pipe(), 
> execve()

### Voici un exemple du fonctionnement de ce projet :

  Ligne de commande entrée dans le terminal :
  ```< infile cmd1 | cmd2 > outfile ```
  
  Ligne de commande entrée par l'utilisateur dans le projet pipex :
  ```./pipex infile cmd1 cmd2 outfile```

### Idée globale du projet :

Nous lisons depuis *l'infile* et exécutons la première commande, puis nous exécutons la seconde commande avant de rediriger la sortie de celle-ci vers *l'oufile*.
```pipe()``` envoie le résultat du premier ```execve()``` en *input* du second ```execve()```. ```fork()``` lance par la suite deux processus dans un seul programme, et ```dup2()``` échange les fichiers avec stdin et stdout.

A noter que lors d'un ```fork()``` les processus lancés sont, silmultanés. Ils se produisent donc en **même temps**.

Les nouveautées majeures dans ce projet, en plus des fonctions ```fork(), pipe(), dup2()``` sont les variables d'environnement directement appelées dans le main.

```int main(int argc, char **argv, char **envp)```

Pour comprendre ce que celles-ci impliquent, je vous invite à taper ```env``` dans votre terminal.
La ligne ```PATH```, contient les répertoires de toutes les commandes binaires.

Elles nous sont indispensables dans ce projet pour reproduire le comportement de Shell.

Une fois toutes ces notions aquises, Pipex n'a plus de secrets pour vous ! 
