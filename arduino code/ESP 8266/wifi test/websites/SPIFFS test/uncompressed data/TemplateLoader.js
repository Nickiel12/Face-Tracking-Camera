

    var templatesImport = document.getElementById('MasterTemplate');
    var templates = templatesImport.import;
    var template = templates.getElementById('FullTemplate')
    document.body.appendChild(document.importNode(template, true));
