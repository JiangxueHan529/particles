#version 400

layout (location = 0) in vec3 vPos;

uniform vec3 uCameraPos;
uniform float uSize;
uniform vec3 uOffset;
uniform vec4 uColor;
uniform mat4 uVP;
out vec4 color;
out vec2 uv;

void main()
{
   color = uColor;
   uv = vPos.xy;
   vec3 translate = uOffset - uSize/2.0f;
   mat4 translateMatrix = mat4(1.0, 0.0, 0.0, 0.0,
							   0.0, 1.0, 0.0, 0.0,
							   0.0, 0.0, 1.0, 0.0,
							   translate, 1.0);
   vec3 up = vec3(0.0, 1.0, 0.0);
   vec3 z = normalize(uCameraPos);
   vec3 x = cross(up, z);
   vec3 y = cross(z, x);
   mat4 rotationMatrix = mat4(x, 0.0, y, 0.0, z, 0.0, 0.0, 0.0, 0.0, 1.0);
   mat4 scaleMatrix = mat4(uSize, 0.0,0.0,0.0,
						   0.0,uSize,0.0,0.0,
						   0.0,0.0,uSize,0.0,
						   0.0,0.0,0.0,1.0);
   
   gl_Position = uVP * rotationMatrix*translateMatrix*scaleMatrix * vec4(vPos, 1.0);
}
