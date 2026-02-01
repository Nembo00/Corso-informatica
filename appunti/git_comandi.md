# 💻 Comandi Git più Utili e Frequenti

Questa tabella riassume i comandi più usati di Git, suddivisi per categoria.  
Utile come riferimento rapido per lavorare con repository locali e remote.

---

## 🧭 Configurazione di base

| Azione | Comando | Descrizione |
|--------|----------|-------------|
| Impostare il nome utente | `git config --global user.name "Jacopo"` | Serve per firmare i commit |
| Impostare l'email utente | `git config --global user.email "jacopo@example.com"` | Collegata al tuo account Git |
| Vedere la configurazione | `git config --list` | Mostra le impostazioni correnti |

---

## 📂 Creazione e clonazione repository

| Azione | Comando | Descrizione |
|--------|----------|-------------|
| Inizializzare una nuova repo | `git init` | Crea una repo Git nella cartella corrente |
| Clonare una repo esistente | `git clone <url>` | Copia una repo remota in locale |
| Aggiungere un remoto | `git remote add origin <url>` | Collega la repo locale a quella remota |
| Mostrare i remoti configurati | `git remote -v` | Elenca gli URL remoti associati |

---

## 🧱 Lavoro sui file

| Azione | Comando | Descrizione |
|--------|----------|-------------|
| Vedere lo stato della repo | `git status` | Mostra file modificati, aggiunti o non tracciati |
| Aggiungere un file | `git add nomefile` | Aggiunge un file allo staging area |
| Aggiungere tutto | `git add .` | Aggiunge tutti i file nuovi/modificati |
| Rimuovere un file | `git rm nomefile` | Rimuove il file anche dal disco |
| Rimuovere solo dal tracciamento | `git rm --cached nomefile` | Mantiene il file sul disco ma lo toglie dalla repo |
| Ripristinare un file modificato | `git restore nomefile` | Riporta il file all’ultimo commit |
| Ignorare file futuri | `.gitignore` | Elenco dei file da escludere dal tracciamento |

---

## 💾 Commit e cronologia

| Azione | Comando | Descrizione |
|--------|----------|-------------|
| Creare un commit | `git commit -m "messaggio"` | Registra i cambiamenti nello storico |
| Modificare l’ultimo commit | `git commit --amend` | Cambia messaggio o aggiunge file al commit precedente |
| Vedere la cronologia | `git log` | Mostra tutti i commit |
| Cronologia compatta | `git log --oneline` | Mostra solo hash e messaggi |
| Mostrare differenze | `git diff` | Visualizza differenze tra versioni |

---

## 🌐 Repository remota

| Azione | Comando | Descrizione |
|--------|----------|-------------|
| Scaricare aggiornamenti | `git pull` | Recupera e unisce modifiche dal remoto |
| Inviare commit | `git push` | Carica i tuoi commit sulla repo remota |
| Impostare ramo di default | `git push -u origin main` | Collega la branch locale al remoto |
| Mostrare rami remoti | `git branch -r` | Elenca le branch remote disponibili |

---

## 🌳 Branch e fusioni

| Azione | Comando | Descrizione |
|--------|----------|-------------|
| Mostrare le branch | `git branch` | Elenca le branch locali |
| Creare una nuova branch | `git branch nome_branch` | Crea una nuova branch |
| Passare a un’altra branch | `git checkout nome_branch` | Cambia branch |
| Creare e spostarsi in una branch | `git checkout -b nome_branch` | Crea e passa subito alla nuova branch |
| Fondere una branch | `git merge nome_branch` | Unisce modifiche da un’altra branch |
| Eliminare una branch | `git branch -d nome_branch` | Cancella una branch locale |

---

## 🧹 Pulizia e ripristino

| Azione | Comando | Descrizione |
|--------|----------|-------------|
| Scartare modifiche locali | `git restore nomefile` | Ripristina file modificati |
| Scartare tutto | `git restore .` | Ripristina tutti i file modificati |
| Tornare a un commit specifico | `git checkout <hash>` | Riporta la repo a una versione passata |
| Eliminare file non tracciati | `git clean -f` | Cancella file non gestiti da Git |

---

## 🔍 Info rapide

| Azione | Comando | Descrizione |
|--------|----------|-------------|
| Vedere differenze rispetto all’ultimo commit | `git diff HEAD` | Mostra modifiche locali |
| Vedere su quale branch sei | `git branch --show-current` | Mostra la branch attiva |
| Mostrare l’ultimo commit | `git show` | Visualizza dettagli del commit più recente |

---

📘 **Suggerimento:**  
Tenere questo file nella root della repo come riferimento rapido è molto comodo, soprattutto in laboratorio o quando lavori su più progetti.

