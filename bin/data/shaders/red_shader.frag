#version 120

uniform sampler2DRect tex0;
uniform vec3 chromaKeyColor;
varying vec2 texCoordVarying;

void main()
{
    vec4 texel0 = texture2DRect(tex0, texCoordVarying);
    
    if (texel0.r == 1 && texel0.g == 0 && texel0.b == 0){
        discard;
    }else{
        gl_FragColor = texel0;
    }
    
}