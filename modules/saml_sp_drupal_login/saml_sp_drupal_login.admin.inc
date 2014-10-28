<?php

/**
 * @file
 * Admin pages for the SAML Drupal Login module
 */

/**
 * Configure which IDP to use when authenticating with Drupal.
 */
function saml_sp_drupal_login__admin_config_form($form, &$form_state) {
  // List all the IDPs in the system.
  foreach (saml_sp__load_all_idps() as $machine_name => $idp) {
    $idps[$machine_name] = $idp->name;
  }

  $form['saml_sp_drupal_login__idp'] = array(
    '#type' => 'select',
    '#options' => $idps,
    '#title' => t('IdP'),
    '#description' => t('Choose the IdP to use when authenticating Drupal logins'),
    '#default_value' => variable_get('saml_sp_drupal_login__idp', ''),
  );

  $form['saml_sp_drupal_login__logout'] = array(
    '#type'           => 'checkbox',
    '#title'          => t('Single Log Out'),
    '#description'    => t('When logging out of %site_name also log out of the IdP', array('%site_name' => variable_get('site_name', 'Drupal'))),
    '#default_value'  => variable_get('saml_sp_drupal_login__logout', TRUE),
  );

  return system_settings_form($form);
}
