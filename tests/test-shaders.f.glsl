#version 150

in vec2 f_tex_coord;
in vec4 f_color;
uniform sampler2D texture;

out vec4 color;

void main( ) {
	//color = f_color;
	color = f_color + texture( texture, f_tex_coord );
}
