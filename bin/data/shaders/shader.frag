#version 120

uniform sampler2DRect tex0;
uniform float threshold;
uniform vec3 chromaKeyColor;
varying vec2 texCoordVarying;

void main()
{
    vec4 texel0 = texture2DRect(tex0, texCoordVarying);

    float brightness = (0.2126*texel0.r + 0.7152*texel0.g + 0.0722*texel0.b);
    if (brightness > threshold){
        discard;
    }else{
        gl_FragColor = texel0;
    }
}