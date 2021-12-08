# cpp_cli_template

A cross platform cmake template for cli app, with logging, and configuration.

## Using the template on Windows

```
git clone --recursive https://github.com/TheFern2/cpp_cli_template.git
```

1. Launch cmake gui:

![](/images/project_1.PNG)

Point to root dir of repo for the source code. For the project, I make a build dir, it can be named anything.

2. Configure your desired project, I use vs2019 on x64.

![](/images/configure_2.PNG)

3. Hit configure.
4. Hit generate.

Browse to your build project, and launch the solution or open project button from cmake gui.

5. Set cpp_cli_template as startup project.
6. Go to project/properties/Linker/System change SubSystem to Console.
7. Run/debug you should see a simple green circle, and a log message.

# Using template on linux

The process is always much easier on linux. :)

```
git clone https://github.com/TheFern2/cpp_cli_template.git
```

Install libraries:
```
sudo apt-get install libjsoncpp-dev
sudo apt install libspdlog-dev
```

https://github.com/TheFern2/cpp_game_dev_templates/blob/main/docs/linux/setup.md

To build you can run `./install.sh`, to edit project use favorite editor, i.e. clion, vscode, etc.