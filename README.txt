SAML Service Provider
=====================

This module allows Drupal to become a "Service Provider" for SAML.

This means that users can authenticate to Drupal (without entering a username
or password) by delegating authenticate to a SAML IDP (Identity Provider).


Dependencies
============

Requires the OneLogin SAML-PHP toolkit, downloaded to the 'saml_sp/lib' folder:

`cd lib`
`git clone https://github.com/onelogin/php-saml.git .`

