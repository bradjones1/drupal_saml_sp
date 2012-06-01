<?php
/**
 * @file
 * Admin pages for the SAML Service Provider module.
 */

/**
 * Menu callback for admin/configure/people/saml_sp
 *
 * @ingroup forms
 */
function saml_sp__admin_config_form($form, &$form_state) {
  $form['saml_sp__idp_url'] = array(
    '#type' => 'textfield',
    '#title' => t('IDP URL'),
    '#description' => t('Login URL of the Identity Provider server.'),
    '#default_value' => variable_get('saml_sp__idp_url', ''),
    '#required' => TRUE
  );
  $form['saml_sp__app_name'] = array(
    '#type' => 'textfield',
    '#title' => t('App name'),
    '#description' => t('String used to identify this application to Identity Providers.'),
    '#default_value' => variable_get('saml_sp__app_name', DRUPAL_SAML_SP__APP_NAME_DEFAULT),
  );
  $form['saml_sp__x509_cert'] = array(
    '#type' => 'textarea',
    '#title' => t('x.509 Certificate'),
    '#description' => t('Enter the application certificate provided by the IDP.'),
    '#default_value' => variable_get('saml_sp__x509_cert', ''),
    '#required' => TRUE
  );

  return system_settings_form($form);
}
