# Sandbox for OpenGL

This is the boiler template for OpenGL. It contains the base needed for OpenGL to be up and running.
There is example of traingle drawn using Array method in main program.

<h2>How to use it</h2>
Before using this few key points is to be known about folder hierarchical structure:
<ul>
  <li>builds - contains makefile, binary exectuable (inside Exe folder) and all the object file produced (for faster linking later on)</li>
  <li>includes - contains all the necessary files that are to be included (GLAD - loader, GLFW - context, khr - dependencies, lib - lib for mac and win(dll *required)</li>
  <li>res - contains Shaders used by program (mainly, ver.shader for Vertex and frag.shader for Fragment)</li>
  <li>src > Helpers - contain basic class of Shader and Window (can add more as per need)</li>
  <li>src > glad.cpp - required(for loading function pointer..macros.. and so on)</li>
  <li>src > main.cpp - main entry point of the program</li>
  <li>glfw3.dll - dll for windows(if required)</li>
  <li>(#OPTIONAL) cppGenerator.py - python script to generate new cpp file of given class with few boiler generated (mainly constructor.. and include..)</li>
</ul>

<hr>
<h2>Now, Follow as :</h2>
<ul>
  <li>Clone the project <code> git clone https://github.com/Thaparoshan143/OpenGL_Sandbox</code></li>
  <li>Change the code as per need with entry point at main.cpp</li>
  <li>Makefile is used for the compiling and running so, Change the working directory to builds (to use makefile for compiling) in terminal (VScode)</li>
  <li>type command in terminal : <code>make mac_m</code> - for mac and <code>make win_m</code> - for windows</li>
  <li>run test</li>
</ul>

<h3># Warning: This boiler is made using mac system. Few things might need change eg: -</h3>
<li>directory change with / -> \</li> and few more..
