#version 330

#define NR_POINT_LIGHTS 4

struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

struct DirLight {
	vec3 direction;

	vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight {
	vec3 position;
    
	float constant;
	float linear;
	float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 Normal;
in vec3 FragPos;
in vec2 uv;

out vec4 color;

uniform vec3 viewPos;
uniform Material material;
uniform DirLight dirLight;
uniform PointLight pointLights[NR_POINT_LIGHTS]; 

uniform sampler2D diffuseTex;
uniform sampler2D specularTex;
uniform sampler2D normalMap;

uniform bool hasDiffuseMap;
uniform bool hasSpecularMap;
uniform bool hasNormalMap;

vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir);  

void main()
{
	vec3 norm;
	if(hasNormalMap){
		norm = texture(normalMap, uv).rgb;
		norm = normalize(norm * 2.0 - 1.0);
	}
	else{
		norm = normalize(Normal);
	}
    vec3 viewDir = normalize(viewPos - FragPos);

    vec3 result = CalcDirLight(dirLight, norm, viewDir);

    for(int i = 0; i < NR_POINT_LIGHTS; i++)
        result += CalcPointLight(pointLights[i], norm, FragPos, viewDir);    

    //result += CalcSpotLight(spotLight, norm, FragPos, viewDir);    
    
    color = vec4(result, 1.0);
} 


vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);

    float diff = max(dot(normal, lightDir), 0.0);

	vec3 halfwayDir = normalize(lightDir + viewDir);
    //vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);

    vec3 ambient  = light.ambient  * material.ambient;
    vec3 diffuse  = light.diffuse  * diff * material.diffuse;
    vec3 specular = light.specular * spec * material.specular;

	if(hasSpecularMap)
		specular *= texture(specularTex, uv).rgb;
	if(hasDiffuseMap){
		ambient *= texture(diffuseTex, uv).rgb;
		diffuse *= texture(diffuseTex, uv).rgb;
	}

    return (ambient + diffuse + specular);
}  

vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
    vec3 lightDir = normalize(light.position - fragPos);

    float diff = max(dot(normal, lightDir), 0.0);

	vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), material.shininess);
	//vec3 reflectDir = reflect(-lightDir, normal);
    //float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

    float distance    = length(fragPos - light.position);
    float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    

    vec3 ambient  = light.ambient  * material.ambient;
    vec3 diffuse  = light.diffuse  * diff * material.diffuse;
    vec3 specular = light.specular * spec * material.specular;

	if(hasSpecularMap)
		specular *= texture(specularTex, uv).rgb;
	if(hasDiffuseMap){
		ambient *= texture(diffuseTex, uv).rgb;
		diffuse *= texture(diffuseTex, uv).rgb;
	}

    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + (diffuse + specular));
} 