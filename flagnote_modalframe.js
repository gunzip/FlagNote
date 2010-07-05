;if (Drupal && Drupal.jsEnabled) {
  Drupal.behaviors.flag_note_modalframe = function() {
    $('<div id="#modalframe-example-messages"></div>').appendTo('body');

    $('a.modalframe-flagnote:not(.modalframe-flagnote-processed)')
      .addClass('modalframe-flagnote-processed').click(function()
    {
      var element = this;

      function onSubmitCallbackExample(args, statusMessages) {
        if (statusMessages) {
          $('#modalframe-example-messages').hide().html(statusMessages).show('slow');
        }
        if (args && args.message) {
          alert(args.message);
          window.location.href = window.location.href;
        }
      }

      $('#modalframe-example-messages').hide('fast');

      var modalOptions = {
        url: $(element).attr('href'),
        autoFit: true,
        onSubmit: onSubmitCallbackExample
      };

      Drupal.modalFrame.open(modalOptions);
      return false;
    });
  }
}
