## Añadir cita
**ID**: 14
**Descripción**: El administrador quiere añadir una cita de un usuario registrado.

**Actor principal**: Secretario
**Actor secundario**: Usuario

**Precondiciones**:
* Haber accedido al perfil del paciente.

**Flujo principal**:
1. El administrador quiere ver los datos de un usuario registrado anteriormente.
1. El sistema muestra los datos del usuario y las distintas posibilidades que puede realizar relacionadas con el usuario.
1. El administrador pulsa el botón añadir cita, rellena los campos necesarios y confirma.
1. El sistema guarda la cita y pasa al perfil del usuario.

**Postcondiciones**: 
* Ninguna.

**Flujo alternativo**:
* 3.a Si algún campo está de forma incorrecta tras la confirmación o la cita ya está cogida, se muestra un mensaje de error.
