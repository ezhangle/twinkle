$input v_texcoord0

#include "..\thirdparty\bgfx\bgfx_shader.sh"
#include "..\thirdparty\bgfx-common\shaderlib.sh"

SAMPLER2D(u_texColor, 0);
uniform vec4 u_color;

void main()
{
    gl_FragColor = texture2D(u_texColor, v_texcoord0);
}