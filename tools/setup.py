#!/usr/bin/env python3

#################################
# TMTM Pack Setup Script #
#################################

import os
import sys
import shutil
import platform
import subprocess
import winreg

######## GLOBALS #########
MAINDIR = "tmtm"
PROJECTDIR = "pack"
##########################

def main():
    FULLDIR = "{}\\{}".format(MAINDIR,PROJECTDIR)
    print("""
  ##################################################
  # TMTM Pack Development Environment Setup #
  ##################################################
  This script will create your TMTM Pack dev environment for you.
  Before you run this, you should already have:
    - The Arma 3 Tools installed properly via Steam
    - A properly set up P-drive
  If you have not done those things yet, please abort this script in the next step and do so first.
  This script will create two hard links on your system, both pointing to your TMTM Pack project folder:
    [Arma 3 installation directory]\\{} => TMTM Pack project folder
    P:\\{}                              => TMTM Pack project folder
    """.format(FULLDIR,FULLDIR))

    try:
        reg = winreg.ConnectRegistry(None, winreg.HKEY_LOCAL_MACHINE)
        key = winreg.OpenKey(reg,
                r"SOFTWARE\Wow6432Node\bohemia interactive\arma 3")
        armapath = winreg.EnumValue(key,1)[1]
    except:
        print("Failed to determine Arma 3 Path.")
        return 1

    if not os.path.exists("P:\\"):
        print("No P-drive detected.")
        return 2

    scriptpath = os.path.realpath(__file__)
    projectpath = os.path.dirname(os.path.dirname(scriptpath))

    print("# Detected Paths:")
    print("  Arma Path:    {}".format(armapath))
    print("  Project Path: {}".format(projectpath))

    repl = input("\nAre these correct? (y/n): ")
    if repl.lower() != "y":
        return 3

    print("\n# Creating links ...")

    if os.path.exists("P:\\{}\\{}".format(MAINDIR,PROJECTDIR)):
        print("Link on P: already exists. Please finish the setup manually.")
        return 4

    if os.path.exists(os.path.join(armapath, MAINDIR, PROJECTDIR)):
        print("Link in Arma directory already exists. Please finish the setup manually.")
        return 5

    try:
        if not os.path.exists("P:\\{}".format(MAINDIR)):
            os.mkdir("P:\\{}".format(MAINDIR))
        if not os.path.exists(os.path.join(armapath, MAINDIR)):
            os.mkdir(os.path.join(armapath, MAINDIR))

        if platform.win32_ver()[0] == "7":
            subprocess.call(["cmd", "/c", "mklink", "/D", "P:\\{}\\{}".format(MAINDIR,PROJECTDIR), projectpath])
            subprocess.call(["cmd", "/c", "mklink", "/D", os.path.join(armapath, MAINDIR, PROJECTDIR), projectpath])
        else:
            subprocess.call(["cmd", "/c", "mklink", "/D", "/J", "P:\\{}\\{}".format(MAINDIR,PROJECTDIR), projectpath])
            subprocess.call(["cmd", "/c", "mklink", "/D", "/J", os.path.join(armapath, MAINDIR, PROJECTDIR), projectpath])
    except:
        raise
        print("Something went wrong during the link creation. Please finish the setup manually.")
        return 6

    print("# Links created successfully.")
    return 0


if __name__ == "__main__":
    exitcode = main()

    if exitcode > 0:
        print("\nSomething went wrong during the setup. Make sure you run this script as administrator. If these issues persist, please contact Trenchgun to help you.")
    else:
        print("\nSetup successfully completed.")

    input("\nPress enter to exit ...")
    sys.exit(exitcode)