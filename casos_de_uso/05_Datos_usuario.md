## Datos de usuario
**ID**: 04
**Descripción**: El administrador quiere consultar el perfil de un usuario registrado.

**Actor principal**: Administrador
**Actor secundario**: Usuario

**Precondiciones**:
* Ninguna

**Flujo principal**:
* Primera forma:
1. El administrador quiere consultar los datos de un usuario registrado anteriormente.
1. El administrador accede al listado de usuarios en el menú principal.
1. El administrador introduce su nombre y apellidos en el cuadro de búsqueda.
1. El sistema muestra los datos del usuario y las distintas posibilidades que puede realizar relacionadas con el usuario.

* Segunda forma:
1. El administrador quiere consultar los datos de un usuario registrado anteriormente.
1. El administrador accede al listado de usuarios en el menú principal.
1. El administrador busca manualmente el usuario en el listado y pincha en su nombre.
1. El sistema muestra los datos del usuario y las distintas posibilidades que puede realizar relacionadas con el usuario.

**Postcondiciones**: 
* Ninguna

**Flujo alternativo**:
* Primera forma:
3.a Si el nombre buscado no coincide con ninguno registrado, se muestra un mensaje de error.
