<?php

// Plugin definition
$plugin = array(
  'title' => t('Bootstrap carousel'),
  'description' => t('Presents the panes in a bootstrap carousel'),
  'render region' => 'ds_bootstrap_slider_style_render_region',
  'settings form' => 'ds_bootstrap_slider_style_settings_form',
);
function theme_ds_bootstrap_slider_style_render_region($vars) {
  $id = drupal_html_id($vars['region_id'] . '-ds-carousel');
  $vars['settings']['id'] = $id;

  return theme('ds_bootstrap_slider', array('items' => $vars['panes'], 'settings' => $vars['settings'], 'pane'));
}

function ds_bootstrap_slider_style_settings_form($settings) {
  $form['interval'] = array(
    // Use a select box widget
    '#type' => 'textfield',
    // Widget label
    '#title' => t('Interval'),
    // Helper text
    '#description' => t('The amount of time to delay between automatically cycling an item. If false, carousel will not automatically cycle.'),
    // Get the value if it's already been set
    '#default_value' => (!$settings['interval']) ? 5000 : $settings['interval'],
  );
  $form['pause'] = array(
    // Use a textbox
    '#type' => 'textfield',
    // Widget label
    '#title' => t('Pause'),
    // helper text
    '#description' => t('Pauses the cycling of the carousel on mouseenter and resumes the cycling of the carousel on mouseleave.'),
    // Get the value if it's already been set
    '#default_value' => (!$settings['pause']) ? "hover" : $settings['pause'],
  );
  $form['wrap'] = array(
    // Use a textbox
    '#type' => 'checkbox',
    // Widget label
    '#title' => t('Wrap'),
    // helper text
    '#description' => t('Whether the carousel should cycle continuously or have hard stops.'),
    '#return_value' => 1,
    // Get the value if it's already been set
    '#default_value' => (!$settings['wrap']) ? 1 : $settings['wrap'],
  );
  $form['start'] = array(
    // Use a textbox
    '#type' => 'textfield',
    // Widget label
    '#title' => t('Start item'),
    // helper text
    '#description' => t('Whether the carousel should cycle continuously or have hard stops.'),
    '#return_value' => 1,
    // Get the value if it's already been set
    '#default_value' => (!$settings['start']) ? 1 : $settings['start'],
  );
  return $form;
}

