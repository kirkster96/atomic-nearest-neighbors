# atomic-nearest-neighbors

This is a simple Windows C++ command-line application that allows the user to read a VASP POSCAR file and print an ordered list of the nearest-neighbors to the terminal.

Currently, this program only supports POSCARS that are in "Direct" mode. Learn more about the POSCAR file format here: https://www.vasp.at/wiki/index.php/POSCAR

## To use this program:
1. Place the application (Release/dopingApp.exe) in a folder containing POSCAR files.
2. Open the folder using Windows PowerShell. (view the folder and shift +  right-click to open PowerShell window in that folder)
3. Type ./dopingApp [REPLACE WITH POSCAR FILE NAME]
4. Follow the on-screen prompts to run the program.

<img src="https://github.com/kirkster96/atomic-nearest-neighbors/blob/master/docs/_static/sample_output_v0_1_0.PNG?raw=true" width="500">

## Changelog
v0.1.0, Jan 10, 2021 -- Initial release.
