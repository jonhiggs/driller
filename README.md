# driller

Driller's primary purpose is to clean and standardise paths.

- Tilde's (~) are always expanded.
- Directories always have a trailing slash.
- Files never have a trailing slash (including symlinks to directories).
- Collapse ../ in paths.
- Remove // from paths.
- Wildcards are honoured and multiple results will be returned.


## Requirements

Nothing special...


## Installation

To install run the following commands in sequence.

```bash
dest="/usr/local/bin/driller"
tag="latest"
sudo wget https://raw.githubusercontent.com/jonhiggs/driller/${tag}/driller -O "${dest}"
chmod +x "${dest}"
```


## Usage

`driller <OPTION> <PATH>`


## Options

| Switch            | Description                                           |
|-------------------|-------------------------------------------------------|
| -a, --absolute    | Absolute path (default).                              |
| -b, --basename    | Strip directory from path.                            |
| -D, --dereference | Recursively find the ultimate target of a symlink.    |
| -d, --dirname     | Strip file from path.                                 |
| -s, --scm         | Find the SCM root (git or hg) for file.               |
|     --version     | Version information.                                  |

## Notes

1. `--dereference` is the same as the `--canonicalize` option in GNU readlink. Most helpful if you only have only have the BSD readlink.
