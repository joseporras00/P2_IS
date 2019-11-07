## Borrar tratamiento
**ID**: 09
**Descripción**: Se borra el tratamiento actual del paciente.

**Actor principal**: Secretario
**Actor secundario**: Todos los usuarios

**Precondiciones**:
* Ninguna

**Flujo principal**:
1. El secretario quiere borrar el tratamiento de un paciente.
1. El secretario accede a la función desde el usuario.
1. El secretario borra su tratamiento y se añade al historial.

**Postcondiciones**: 
* El tratamiento queda guardado en el historial del paciente.

**Flujo alternativo**:
* 3.a Se muestra un mensaje de confirmación.
