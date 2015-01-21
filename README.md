# driller

Driller's purpose is to normalise paths.

- Paths like `/this/is/a/../../path/` will turn into `/this/path/`.

- Directories will always end in a trailing slash, files will never end in a slash.

- Wildcards will be honoured.

- Easily find the root of a Git or Mercurial repository.


## Requirements

Nothing special...


## Usage

`driller <OPTION> <PATH>`


## Options

| Switch     | Description                             |
|------------|-----------------------------------------|
| --absolute | Provide the absolute path (default).    |
| --basename | Provide the filename from a path.       |
| --dirname  | Provide the dirname from a path.        |
| --scm      | Find the SCM root (git or hg).          |
| --parent   | Return clean path of parent directory.  |
