<?php
/**
 * @file
 * User pages for the SAML Service Provider module.
 */


/**
 * Page callback to complete the SAML authentication process.
 */
function saml_sp__endpoint() {
  // Check that the request is a POST and contains a SAMLResponse parameter.
  if ($_SERVER['REQUEST_METHOD'] != 'POST' || empty($_POST['SAMLResponse'])) {
    // Not a valid incoming auth-message from an IDP, so abort.
    drupal_goto('');
  }

  $settings = saml_sp__get_settings();
  $samlResponse = new OneLogin_Saml_Response($settings, $_POST['SAMLResponse']);

  try {
    if ($samlResponse->isValid()) {
      drupal_set_message('You are: ' . $samlResponse->getNameId() . '<br>');
      $attributes = $samlResponse->getAttributes();
      if (!empty($attributes)) {
        $msg = 'You have the following attributes:<br>';
        $msg .= '<table><thead><th>Name</th><th>Values</th></thead><tbody>';
        foreach ($attributes as $attributeName => $attributeValues) {
          $msg .= '<tr><td>' . htmlentities($attributeName) . '</td><td><ul>';
            foreach ($attributeValues as $attributeValue) {
              $msg .= '<li>' . htmlentities($attributeValue) . '</li>';
            }
            $msg .= '</ul></td></tr>';
        }
        $msg .= '</tbody></table>';
        drupal_set_message($msg);
      }
    }
    else {
      drupal_set_message('Invalid SAML response.');
    }
  }
  catch (Exception $e) {
    drupal_set_message('Invalid SAML response: ' . $e->getMessage());
  }
  drupal_goto('');
}

