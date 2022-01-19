import os , platform

WorkingPlatform = platform.system()

print('Detected OS is: ' + WorkingPlatform)

if (WorkingPlatform == "Linux"):
    print("Warning You Must Have G++ , Make , and Raylib 4.0.0 Installed to Continue... Do You Have all of these Things ( 1 / 0 ): ")
    
    Option = input()

    if (Option == 1):
        print("Starting Build")
        os.system("mkdir Build")
        os.system("cd HDSourceCode;make")
        os.system("cp -r HDSourceCode/WispHD Build")

        os.system("cd Data;unzip HDGameData.zip")

        os.system("cp -r Data/GameAssets/ Build")
        os.system("cp -r Data/LevelData/ Build")

        print("Done !")
        print("Enjoy    - Liquid")
        
else:
    print("Sorry Build Scripts are only on Linux.. Sorry")



