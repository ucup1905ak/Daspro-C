| Code        | What it does                     |
| ----------- | -------------------------------- |
| `\033[H`    | Move cursor to top-left          |
| `\033[2J`   | Clear entire screen              |
| `\033[2K`   | Clear entire line                |
| `\033[nA`   | Move cursor up `n` lines         |
| `\033[nB`   | Move cursor down `n` lines       |
| `\033[n;1H` | Move cursor to row `n`, column 1 |
| \r          | to start of the line             |

##### Set Forground Color
`\033[38;2;r;g;bm  >> r: red , g: green, b: blue`

##### Set Background Color
`\033[48;2;r;g;bm  >> r: red , g: green, b: blue`