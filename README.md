# Sandbox-2 for OpenGL

This is the boiler template for OpenGL. It contains the base needed for OpenGL to be up and running with few library packed, in <code>include</code> directory. 

<code>
<ul>
  <li>GLFW - OpenGL Context (for creating windows, handling inputs...)</li>
  <li>GLAD - OpenGL Loaders (to load openGL function pointers in ease)</li>
  <li>GLM - Math Library(includes vectors, matrix,...)</li>
  <li>Freetype - Text Loading Library (Glyph based)</li>
  <li>Stb - Image manipulation (reading, writing,...)</li>
</ul>
</code>

<b>If only basic boiler required, use main branck</b> : https://github.com/Thaparoshan143/OpenGL_Sandbox
<h2>Follow as :</h2>
<ul>
  <li>Clone the project <code>git clone https://github.com/Thaparoshan143/OpenGL_Sandbox</code></li>
  <li>Change the code as per need with entry point at main.cpp (in sandbox)</li>
  <li>Makefile is used for the compiling and building. Change the working directory to builds (to use makefile for compiling) in terminal. Inspect and change Makefile according to requirement.</li>
  <li>type command in terminal : <code>make build_m</code>(Platform will be auto detected by Makefile)</li>
  <li>Then run test (is inside builds/Exe/)</li>
</ul>

### Warning: This boiler is made using mac system (M1). Few things might need change on other patform eg: -
<li>directory change with / -> \</li>
<li>Few of the dll might be missing while .exe launch</li>

<h5>Note: Dll should be in same folder as .exe (in window)<h5>
